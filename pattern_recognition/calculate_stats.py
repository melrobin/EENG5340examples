
fid=open('features.txt','r')
X_read=fid.readlines()
X=[]
for i in range(len(X_read)):
   the_line=X_read[i].rstrip('\n').split(',')
   for var in range(len(the_line)):
      if (var > 0):
         the_line[var]=float(the_line[var])
   X.append(the_line)
      

print X
X_mean=[0,0,0,0,0]
for i in range(len(X)):
   for var in range(len(X[i])):
      if (var >0):
         X_mean[i]=X_mean[i]+X[i][var]       
   
print X_mean
#print X_read
   

