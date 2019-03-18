function [] = gener_graphe( nom_fichier )
fileID=fopen(nom_fichier);
taille_c=fgetl(fileID);
taille=str2double(taille_c);

Nom=cell(1,taille);
Coor=zeros(taille,2);

for i=1:taille
    C=fgetl(fileID); 
    vec=strsplit(C);
    Nom(1,i)=vec(1);
    x=str2double(vec{2});
    y=str2double(vec{3});
    Coor(i,1)=x;
    Coor(i,2)=y;
  
        
end


    plot(Coor(:,1),Coor(:,2),'b-',Coor(:,1),Coor(:,2),'rx'); %on dessine dans l'espace une répresnation exacte
    axis([-1 6 -1 6]);


fclose(fileID);

end

