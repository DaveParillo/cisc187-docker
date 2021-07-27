FROM debian:bullseye-slim

LABEL maintainer="Dave Parillo <dparillo@sdccd.edu>"

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        bash \
        bc \
        ca-certificates \
        clang-11 \
        clang-tidy-11 \
        clang-tools-11 \
        clang-format-11 \
        cmake \
        cppcheck \
        g++ \
        gcc \
        gdb \
        git \
        libc-dev \
        libc++-11-dev \
        libc++abi-11-dev \
        libclang-common-11-dev \
        libclang-11-dev \
        libclang1-11 \
        libfuzzer-11-dev \
        lld-11 \
        lldb-11 \
        make \
        openssh-client \
        valgrind \
        vim \
    && rm -rf /var/lib/apt/lists/* \
    && update-alternatives \
         --install /usr/bin/clang clang /usr/bin/clang-11 100 \
         --slave /usr/bin/clang++ clang++ /usr/bin/clang++-11 \
         --slave /usr/bin/clang-apply-replacements clang-apply-replacements /usr/bin/clang-apply-replacements-11 \
         --slave /usr/bin/clang-change-namespace clang-change-namespace /usr/bin/clang-change-namespace-11 \
         --slave /usr/bin/clang-check clang-check /usr/bin/clang-check-11 \
         --slave /usr/bin/clang-cl clang-cl /usr/bin/clang-cl-11 \
         --slave /usr/bin/clang-cpp clang-cpp /usr/bin/clang-cpp-11 \
         --slave /usr/bin/clang-doc clang-doc /usr/bin/clang-doc-11 \
         --slave /usr/bin/clang-extdef-mapping clang-extdef-mapping /usr/bin/clang-extdef-mapping-11 \
         --slave /usr/bin/clang-format clang-format /usr/bin/clang-format-11 \
         --slave /usr/bin/clang-format-diff clang-format-diff /usr/bin/clang-format-diff-11 \
         --slave /usr/bin/clang-include-fixer clang-include-fixer /usr/bin/clang-include-fixer-11 \
         --slave /usr/bin/clang-move clang-move /usr/bin/clang-move-11 \
         --slave /usr/bin/clang-offload-bundler clang-offload-bundler /usr/bin/clang-offload-bundler-11 \
         --slave /usr/bin/clang-offload-wrapper clang-offload-wrapper /usr/bin/clang-offload-wrapper-11 \
         --slave /usr/bin/clang-query clang-query /usr/bin/clang-query-11 \
         --slave /usr/bin/clang-refactor clang-refactor /usr/bin/clang-refactor-11 \
         --slave /usr/bin/clang-rename clang-rename /usr/bin/clang-rename-11 \
         --slave /usr/bin/clang-reorder-fields clang-reorder-fields /usr/bin/clang-reorder-fields-11 \
         --slave /usr/bin/clang-scan-deps clang-scan-deps /usr/bin/clang-scan-deps-11 \
         --slave /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-11 \
         --slave /usr/bin/clang-tidy-diff clang-tidy-diff /usr/bin/clang-tidy-diff-11.py \
    && update-alternatives \
         --install /usr/bin/lldb lldb /usr/bin/lldb-11 100
       
WORKDIR /mnt/cisc187
RUN groupadd -g 9999 mesa \
    && useradd -m -u 9999 -g mesa mesa \
    && chown -R mesa:mesa /home/mesa \
    && chown -R mesa:mesa /mnt/cisc187
USER mesa

ENV LANG en_US.UTF-8
ENV PATH /home/mesa/bin:$PATH
ENV PACK_DIR /home/mesa/.vim/pack/default/start

COPY --chown=mesa:mesa examples /home/mesa/examples
COPY --chown=mesa:mesa scripts /home/mesa/bin
COPY --chown=mesa:mesa _vimrc /home/mesa/.vimrc
COPY --chown=mesa:mesa _gitconfig /home/mesa/.gitconfig
COPY --chown=mesa:mesa _clang_format /mnt/.clang_format

RUN mkdir -p /home/mesa/bin \
    && mkdir -p ${PACK_DIR} \
    && cd ${PACK_DIR} \
    && git clone --depth=1 https://tpope.io/vim/commentary.git \
    && git clone --depth=1 https://tpope.io/vim/fugitive.git \
    && git clone --depth=1 git://github.com/vhdirk/vim-cmake.git \
    && vim -u NONE --not-a-term \
           -c "helptags commentary/doc" \
           -c "helptags fugitive/doc" \
           -c "helptags vim-cmake/doc" \
           -c q

ENTRYPOINT ["/bin/bash"]

