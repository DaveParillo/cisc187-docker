// from https://gist.github.com/valbaca/4dd7a123ace1cfe562b77fd12d2a51c7#file-bad_padding-c


char cId[5];
if (id < 10) {
    sprintf(cId, "000%d", id);
} else if (id < 100) {
    sprintf(cId, "00%d", id);
} else if (id < 1000) {
    sprintf(cId, "0%d", id);
} else {
    sprintf(cId, "%d", id);
}
