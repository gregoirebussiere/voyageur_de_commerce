function [G] = gener_graphe_2( nom_fichier )
fileID=fopen(nom_fichier);
taille_c=fgetl(fileID);
taille=str2double(taille_c);

Nom=cell(1,taille);
Coor=zeros(taille,2);
voisins=zeros(taille);


for i=1:taille
    C=fgetl(fileID); 
    vec=strsplit(C);
    Nom(1,i)=vec(1);
    x=str2double(vec{2});
    y=str2double(vec{3});
    Coor(i,1)=x;
    Coor(i,2)=y;
    
    for j=1:taille
        voisins(i,j)=str2double(vec{j+3});
    end    
       
  
        
end



D=pdist(Coor,'euclidean');



%lecteur de voisins pour connaitre le nombre de voisins pour chaque sommet

t=zeros(1,taille*(taille-1)/2);
source=zeros(1,taille*(taille-1)/2);
D=zeros(1,taille*(taille-1)/2);
compteur=1;

for i=1:taille
    nombre=0;
    for j=(1+i):taille
        if voisins(i,j)==1;
            source(1,compteur)=i;
            t(1,compteur)=j;
            D(1,compteur)=pdist([Coor(i,1) Coor(i,2) ; Coor(j,1) Coor(j,2)], 'euclidean');
            compteur=compteur+1;
            
        end 
    end    
end


compteur=1;
while (source(1,compteur)~=0)&&(compteur<taille*(taille-1)/2)
    compteur=compteur+1;
end

source=source(1:compteur);
t=t(1:compteur);
D=D(1:compteur);





G=digraph(source,t,D,Nom);
H=plot(G,'--','layout','force','EdgeLabel',G.Edges.Weight);


%highlight du chemin le plus simple 0 1 2 3 etc...

s_chemin=[1 2 3 4 5 6 7 8 9];
t_chemin=[2 3 4 5 6 7 8 9 10];

highlight(H,s_chemin,t_chemin,'LineStyle','-','EdgeColor','r','LineWidth',1.5)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


fclose(fileID);