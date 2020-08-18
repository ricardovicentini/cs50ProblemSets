int main(void)
{
    int height = collect_input();

    //repeat n times according to the number in height
    for (int currLine = 0; currLine < height; currLine++)
    {
        //calculates the quantity of spaces to be filled
        int nbrOfSpaces = (height - currLine) - 1;
        //calculates the quantity of hashes to be filled
        int nbrOfHashes = currLine + 1;

        fill_with_spaces(nbrOfSpaces);
        fill_with_hashes(nbrOfHashes);
        printChar(" ", 2);
        fill_with_hashes(nbrOfHashes);
        printf("\n");
    }
}

int collect_input()
{
    int height = 0;
    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 8);
    return height;
}
void fill_with_spaces(int width)
{
    printChar(" ", width);
}

void fill_with_hashes(int width)
{
    printChar("#", width);
}

void printChar(string character, int quantity)
{
    for (int i = 0; i < quantity; i++)
    {
        printf("%s", character);
    }
}
