FROM debian:unstable-slim

LABEL maintainer="Dave Parillo <dparillo@sdccd.edu>"

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        bash \
        bc \
        ca-certificates \
        clang-14 \
        clang-tidy-14 \
        clang-tools-14 \
        clang-format-14 \
        cmake \
        cppcheck \
        g++ \
        gcc \
        gdb \
        git \
        libc-dev \
        libc++-14-dev \
        libc++abi-14-dev \
        libclang-common-14-dev \
        libclang-14-dev \
        libclang1-14 \
        libfuzzer-14-dev \
        lld-14 \
        lldb-14 \
        make \
        openssh-client \
        valgrind \
        vim \
    && rm -rf /var/lib/apt/lists/* \
    && update-alternatives \
         --install /usr/bin/clang clang /usr/bin/clang-14 100 \
         --slave /usr/bin/clang++ clang++ /usr/bin/clang++-14 \
         --slave /usr/bin/clang-apply-replacements clang-apply-replacements /usr/bin/clang-apply-replacements-14 \
         --slave /usr/bin/clang-change-namespace clang-change-namespace /usr/bin/clang-change-namespace-14 \
         --slave /usr/bin/clang-check clang-check /usr/bin/clang-check-14 \
         --slave /usr/bin/clang-cl clang-cl /usr/bin/clang-cl-14 \
         --slave /usr/bin/clang-cpp clang-cpp /usr/bin/clang-cpp-14 \
         --slave /usr/bin/clang-doc clang-doc /usr/bin/clang-doc-14 \
         --slave /usr/bin/clang-extdef-mapping clang-extdef-mapping /usr/bin/clang-extdef-mapping-14 \
         --slave /usr/bin/clang-format clang-format /usr/bin/clang-format-14 \
         --slave /usr/bin/clang-format-diff clang-format-diff /usr/bin/clang-format-diff-14 \
         --slave /usr/bin/clang-include-fixer clang-include-fixer /usr/bin/clang-include-fixer-14 \
         --slave /usr/bin/clang-move clang-move /usr/bin/clang-move-14 \
         --slave /usr/bin/clang-offload-bundler clang-offload-bundler /usr/bin/clang-offload-bundler-14 \
         --slave /usr/bin/clang-offload-wrapper clang-offload-wrapper /usr/bin/clang-offload-wrapper-14 \
         --slave /usr/bin/clang-query clang-query /usr/bin/clang-query-14 \
         --slave /usr/bin/clang-refactor clang-refactor /usr/bin/clang-refactor-14 \
         --slave /usr/bin/clang-rename clang-rename /usr/bin/clang-rename-14 \
         --slave /usr/bin/clang-reorder-fields clang-reorder-fields /usr/bin/clang-reorder-fields-14 \
         --slave /usr/bin/clang-scan-deps clang-scan-deps /usr/bin/clang-scan-deps-14 \
         --slave /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-14 \
         --slave /usr/bin/clang-tidy-diff clang-tidy-diff /usr/bin/clang-tidy-diff-14.py \
    && update-alternatives \
         --install /usr/bin/lldb lldb /usr/bin/lldb-14 100
       
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
COPY --chown=mesa:mesa scripts-private /home/mesa/bin
COPY --chown=mesa:mesa scripts /home/mesa/bin
COPY --chown=mesa:mesa _vimrc /home/mesa/.vimrc
COPY --chown=mesa:mesa _gitconfig /home/mesa/.gitconfig
COPY --chown=mesa:mesa _clang_format /mnt/.clang_format

RUN mkdir -p /home/mesa/bin \
    && mkdir -p ${PACK_DIR} \
    && cd ${PACK_DIR} \
    && git clone --depth=1 https://github.com/tpope/vim-commentary.git \
    && git clone --depth=1 https://github.com/tpope/vim-fugitive.git \
    && git clone --depth=1 https://github.com/vhdirk/vim-cmake.git \
    && vim -u NONE --not-a-term \
           -c "helptags commentary/doc" \
           -c "helptags fugitive/doc" \
           -c "helptags vim-cmake/doc" \
           -c q

ENTRYPOINT ["/bin/bash"]

