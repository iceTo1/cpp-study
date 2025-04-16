int strStr(string haystack, string needle)
{
    int hLen = haystack.size();
    int nLen = needle.size();

    if (needle == "") return 0;
    if (hLen < nLen) return -1;

    for (int i = 0; i <= hLen - nLen; ++i)
    {
        int j = 0;
        while (j < nLen && haystack[i + j] == needle[j])
        {
            ++j;
        }

        if (j == nLen)
        {
            return i;
        }
    }

    return -1;
}