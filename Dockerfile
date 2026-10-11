FROM debian:sid-slim

LABEL maintainer="Dave Parillo <dparillo@sdccd.edu>"

RUN apt-get -y update  && apt-get -y upgrade \
    && apt-get install -y --no-install-recommends \
        bash \
        bc \
        ca-certificates \
        clang-21 \
        clang-21-doc \
        clang-tidy-21 \
        clang-tools-21 \
        clang-format-21 \
        cmake \
        cppcheck \
        g++-16 \
        gcc-16 \
        gdb \
        git \
        ghostscript \
        groff \
        libboost-all-dev \
        libc-dev \
        libc++-21-dev \
        libc++abi-21-dev \
        libclang-common-21-dev \
        libclang-21-dev \
        libclang1-21 \
        libfuzzer-21-dev \
        libncurses-dev \
        lld-21 \
        lldb-21 \
        llvm-21-dev \
        make \
        openssh-client
RUN     apt-get install -y --no-install-recommends \
        python3 \
        python3-openai \
        valgrind \
        vim \
    && rm -rf /var/lib/apt/lists/*
    # && rm -rf /var/lib/apt/lists/* \
    # && pip install openai

RUN    update-alternatives \
         --install /usr/bin/clang clang /usr/bin/clang-21 100 \
         --slave /usr/bin/clang++ clang++ /usr/bin/clang++-21 \
         --slave /usr/bin/clang-apply-replacements clang-apply-replacements /usr/bin/clang-apply-replacements-21 \
         --slave /usr/bin/clang-change-namespace clang-change-namespace /usr/bin/clang-change-namespace-21 \
         --slave /usr/bin/clang-check clang-check /usr/bin/clang-check-21 \
         --slave /usr/bin/clang-cl clang-cl /usr/bin/clang-cl-21 \
         --slave /usr/bin/clang-cpp clang-cpp /usr/bin/clang-cpp-21 \
         --slave /usr/bin/clang-doc clang-doc /usr/bin/clang-doc-21 \
         --slave /usr/bin/clang-extdef-mapping clang-extdef-mapping /usr/bin/clang-extdef-mapping-21 \
         --slave /usr/bin/clang-format clang-format /usr/bin/clang-format-21 \
         --slave /usr/bin/clang-format-diff clang-format-diff /usr/bin/clang-format-diff-21 \
         --slave /usr/bin/clang-include-fixer clang-include-fixer /usr/bin/clang-include-fixer-21 \
         --slave /usr/bin/clang-move clang-move /usr/bin/clang-move-21 \
         --slave /usr/bin/clang-offload-bundler clang-offload-bundler /usr/bin/clang-offload-bundler-21 \
         --slave /usr/bin/clang-query clang-query /usr/bin/clang-query-21 \
         --slave /usr/bin/clang-refactor clang-refactor /usr/bin/clang-refactor-21 \
         --slave /usr/bin/clang-rename clang-rename /usr/bin/clang-rename-21 \
         --slave /usr/bin/clang-reorder-fields clang-reorder-fields /usr/bin/clang-reorder-fields-21 \
         --slave /usr/bin/clang-scan-deps clang-scan-deps /usr/bin/clang-scan-deps-21 \
         --slave /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-21 \
         --slave /usr/bin/clang-tidy-diff clang-tidy-diff /usr/bin/clang-tidy-diff-21.py \
    && update-alternatives \
         --install /usr/bin/gcc gcc /usr/bin/gcc-16 100 \
         --slave /usr/bin/g++ g++ /usr/bin/g++-16 \
    && update-alternatives \
         --install /usr/bin/lldb lldb /usr/bin/lldb-21 100
       
WORKDIR /mnt/cisc187
RUN groupadd -g 9999 mesa \
    && useradd -m -u 9999 -g mesa mesa \
    && chown -R mesa:mesa /home/mesa \
    && chown -R mesa:mesa /mnt/cisc187
USER mesa

ENV LANG=en_US.UTF-8
ENV PATH=/home/mesa/bin:$PATH
ENV PACK_DIR=/home/mesa/.vim/pack/default/start

COPY --chown=mesa:mesa examples /home/mesa/examples
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

