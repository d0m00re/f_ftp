#include "client.h"
#include "ft_file.h"
#include <string.h>
#include <stdio.h>
#include "ft_string.h"
#include <stdlib.h>

#include "setting.h"

// formatage de l input
// input [name_file] [data]
// nom du ficher
// data fichier local
// curseur actuel
// size du fichier max
// size du buffer a envoye
char *complete_buffer(char *name_file, char *data_file, size_t *cursor, size_t size_file, size_t *size_buffer)
{
	char *str;
	size_t size_header;

	// step 1 : calcul de la taille a save
	size_header = ft_strlen("put ") + ft_strlen(name_file) + 1;
	*size_buffer = size_header + size_file; // por le moment on prend pas en compte un fichier trop grand pour l buffer 
	// taille du 
	if (size_file - *cursor < SIZE_BUF - size_header) // dans le cas ou la taille restance a ecrire rentre dans notre buffer
		*size_buffer = size_header + (size_file - *cursor);
	else
		*size_buffer = SIZE_BUF;

	// step 2 : allocation de la chaine
	str = malloc(sizeof(char) * (*size_buffer));

	// step 3 : forging string format -> | [put] [name] |  [data]
	ft_strcpy(str, "put ");
	ft_strcat(str, name_file);
	ft_strcat(str, " ");
	strncat(str, data_file, *size_buffer - size_header); // ici on calcul la taille de la chaerge utile a ajouter - la data
	//printf("%s", str);
	printf("*cursor : %lu\n", *cursor);
	*cursor += (*size_buffer - size_header); //increment sur la chaine data_file
	return (str);
}
// pourra surement etre passe en fontion generique
// put path
int manage_put_client(int sock, char **input, char buffer[1024])
{
	char *data_file;
	char *string_to_send;
	size_t size;
	size_t cursor;
	size_t size_buffer;
		
	cursor = 0;
	if (!(data_file = ft_read_file_size(input[1], &size))) //get client data
		return (0);
	while (cursor < size)
	{
		string_to_send = complete_buffer(input[1], data_file, &cursor, size, &(size_buffer));
		//printf("\n%s", string_to_send);
		printf("%zu|%zu|%s\n", size_buffer, ft_strlen(string_to_send), string_to_send);
		if (!string_to_send)
			free(string_to_send);
	}
	free(data_file);
	return (0);
}
