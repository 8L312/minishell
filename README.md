//Explication des fonctions//


`int	search_fct(char *str)`

cherche si une des commandes que l'on doit coder est pr�sente dans str et renvoie son num�ro.
Fonctions et leurs num�ros :
echo -n = 1;
echo = 2;
cd = 3;
pwd = 4;
export = 5;
unset = 6;
env = 7;
exit = 8;



`void	do_fct(int cmd, char *current)`

Re�oit en arg l'int revoy� par search_fct et ex�cute la commande correspondante.



`void ft_echo(int mode, char *str)`

Ecrit la str avec ou sans \n selon le mode :
echo -n = mode 1;
echo = mode 2;



`int	ft_strstr(char *str, char *tofind)`

Un peu diff�rente de la version originale. Cherche si tofind apparait dans str puis renvoie 1 si oui et 0 si aucune occurence n'apparait. (sera utile pour search_fct)
