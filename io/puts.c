int puts(const char *text) {
    int len = strlen(text);
    int ret = write(1, text, len);

    if (ret != len)
        return (-1);

    ret = write(1, "\n", 1);

    if (ret != 1)
        return (-1);

    return 1;
}
