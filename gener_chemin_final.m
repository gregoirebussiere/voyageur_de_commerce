function [ A ] = gener_chemin_final( nom_chemin, nom_graphe )

fileID=fopen(nom_graphe);
taille_c=fgetl(fileID);
taille=str2double(taille_c);

Nom=cell(1,taille);
Coor=zeros(taille,2);

[s_final, t_final,f]=gener_chemin(nom_chemin, nom_graphe);

for i=1:taille
    C=fgetl(fileID); 
    vec=strsplit(C);
    Nom(1,i)=vec(1);
    x=str2double(vec{2});
    y=str2double(vec{3});
    Coor(i,1)=x;
    Coor(i,2)=y;       
end
A=Coor';

A=A(:,t_final');
B=A';

plot(B(:,1),B(:,2),'b-',B(:,1),B(:,2),'rx'); %on dessine dans l'espace une répresnation exacte
    axis([-1 15 -1 12]);
    
for i=1:taille
    text(Coor(i,1)+0.1,Coor(i,2)-0.1,Nom(1,i))

end

f
    txt=['Longeur de chemin : ' num2str(f)];
    text(0,2,txt)

