int levenshtein(string str1, string str2) 
{
	int height = str1.length() + 1;
	int length = str2.length() + 1;
	int** matrix = new int*[height];
	for (int i = 0; i < height; i++) 
	{
		matrix[i] = new int[length];
	}

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < length; j++) 
		{
			if (i == 0 && j == 0) 
			{
				matrix[i][j] = 0;
			}
			else if (i == 0) 
			{
				matrix[i][j] = matrix[i][j - 1] + 1;
			}
			else if (j == 0) 
			{
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			else 
			{
				if (str1[i - 1] == str2[j - 1]) 
				{
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else 
				{
					matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
				}
			}
		}
	}
	return matrix[height - 1][length - 1];
}