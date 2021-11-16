 #include <fstream>

/**
 * @brief Compte le nombre de caractère d'un fichier
 * 
 * @param fileName fichier à lire
 * @return int -1 si erreur et 0 ou plus si ok
 * @result La valeur final est le nombre de charactère dans le fichier ainsi que son nombre de page théorique 
 */

int count(const char* fileName)
{
    std::fstream ifs(fileName, std::ios::in | std::ios::ate);

    size_t cnt = -1;

    // Est ce que le fichier est ouvert correctement ?
    if (!ifs.is_open()) 
    {
        printf("Unable to open the file: %s", fileName);
    } else 
    {
        // On va à la fin du fichier
        ifs.seekg(0, std::fstream::end);
        // On récupère la position du curseur
        // Ce qui permet d'obtenir le nombre de caractère
        cnt = ifs.tellg();
        // On ferme le fichier
        ifs.close();
    }
    
    // On renvoie les données
    return cnt;
}

void countPage(const int totalChar) 
{
    //définit la constante de caractère par ligne de 142
    const int charByLine = 142;
    //obtient le nombre de ligne par la division du nombre total de charactère et du nombre de charactère par ligne
    int line = totalChar / charByLine;

    //Il y a généralement 30 lignes par page donc on divise le nombre de ligne par 30
    int totalPage = line / 30;

    printf("%d pages \n", totalPage);
}

int main(int argc, const char *argv[])
{
    if (argc != 2) 
    {
        printf("Usage: %s <filename>", argv[0]);
        return 1;
    }

    int findChar = count(argv[1]);
    if (findChar == -1) 
    {
        printf("Error while reading while.");
        return 1;
    }

    //Reminder: printf pour faciliter la lecture de l'output
    printf("Character count: %d \n", findChar);
    countPage(findChar);
    return 0;
}
