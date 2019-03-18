function [ s_final, t_final,f ] = gener_chemin( nom_chemin, nom_graphe )
%UNTITLED5 Summary of this function goes here
%  a partir du fichier des chemins et des fichier de la matrice nous
%  pouvons regarder lpes chemins
G=gener_graphe_2(nom_graphe);
M=lecture_chemin(nom_chemin);
a=size(M);
nb_chemin=a(1);


for i=1:nb_chemin
    s=M(i,:);
    f=s(length(s)); %f prend la valuer de fitness et s correspons simplement au chemin
    s=s(1:length(s)-1);
    t=zeros(1,length(s));
    for k=1:(length(s))
        s(k)=s(k)+1;
    end
    %decalage d'indice necessaire du C au matlab
    
    for k=1:(length(s)-1)
        t(k)=s(k+1);

    end

    t(length(t))=s(1);
    %un tri de la liste s et t s doit contenir les nombres les plus petits
    %petite astuce pour simplifier la vie au niveau graphe orienté
    for j=1:length(s)
        if s(j)>t(j)
            temp=t(j);
            t(j)=s(j);
            s(j)=temp;
        end    
    end
    

    %H=plot(G,'--','layout','force','EdgeLabel',G.Edges.Weight);
    %highlight(H,s,t,'LineStyle','-','EdgeColor','r','LineWidth',1.5)
    
    %texte = ['Chemin de longeur ' , num2str(f)];
    %annotation('textbox', [.2 .8 .1 .1], 'FitHeightToText', 'ON', 'Fontsize', 12,'String', texte);
    %delete(texte);
    
    %txt = ['Longeur chemin: ' num2str(f) ' units'];
    %text(10,0.5,txt)
  
    %pause(0.001);
    
    
    
    

end



 s_final=M(nb_chemin,:);
 f=s_final(length(s_final));
 s_final=s_final(1:length(s_final)-1);
   for k=1:(length(s_final))
        s_final(k)=s_final(k)+1;
   end

t_final=zeros(1,length(s_final));
       for k=1:(length(s_final)-1)
        t_final(k)=s_final(k+1);
       end
       
 t_final(length(t_final))=s_final(1); 
 


