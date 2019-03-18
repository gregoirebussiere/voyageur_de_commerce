function [M] = lecture_chemin( nom_fichier )

%le fichier commence par le nombre de chemin a afficher et la taille de la
%population chauqe ligne est un vecteur de chemin composé de taille chiffre
%et un double a la fin qui est la fitness

fileID=fopen(nom_fichier);
taille_c=fgetl(fileID);
taille=str2double(taille_c);
nb_chemin_c=fgetl(fileID);
nb_chemin=str2double(nb_chemin_c);

M=zeros(nb_chemin,taille+1); %taille +1 poru inclure la fitness dans la ligne
for i=1:nb_chemin
    C=fgetl(fileID); 
    vec=strsplit(C);
    for j=1:taille+1
        M(i,j)=str2double(vec{j});
    end    

end

fclose(fileID);