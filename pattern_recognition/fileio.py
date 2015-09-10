import numpy as np
import numpy.random as rnd

classes=['swallow','ostrich','eagle']
features=['height','weight','wingspan','speed']
fname='features.txt'
#The following distributions are N(mu,sigma)
#To transform a X~N(0,1) to X~N(mu,sigma) we say X'=sigma*X+mu
swallow_distributions=[(4,1),(60,10),(3,1),(20,2)]
ostrich_distributions=[(84,2),(100000,60),(84,5),(45,5)]
eagle_distributions=[(12,1),(3200,10),(75,5),(70,1)]
fid=open(fname,'w')
num_patterns=10
for i in range(num_patterns):
   current_class=classes[rnd.randint(0,3)]
   if current_class=='swallow':
      current_height=swallow_distributions[0][1]*rnd.randn()+swallow_distributions[0][0]
      current_weight=swallow_distributions[1][1]*rnd.randn()+swallow_distributions[1][0]
      current_wingspan=swallow_distributions[2][1]*rnd.randn()+swallow_distributions[2][0]
      current_speed=swallow_distributions[3][1]*rnd.randn()+swallow_distributions[3][0] 
   else :
      if current_class=='ostrich':
        current_height=ostrich_distributions[0][1]*rnd.randn()+ostrich_distributions[0][0]
        current_weight=ostrich_distributions[1][1]*rnd.randn()+ostrich_distributions[1][0]
        current_wingspan=ostrich_distributions[2][1]*rnd.randn()+ostrich_distributions[2][0]
        current_speed=ostrich_distributions[3][1]*rnd.randn()+ostrich_distributions[3][0]
      else :
        current_height=eagle_distributions[0][1]*rnd.randn()+eagle_distributions[0][0]
        current_weight=eagle_distributions[1][1]*rnd.randn()+eagle_distributions[1][0]
        current_wingspan=eagle_distributions[2][1]*rnd.randn()+eagle_distributions[2][0]
        current_speed=eagle_distributions[3][1]*rnd.randn()+eagle_distributions[3][0]
   value_to_write=str(current_class)
   fid.write(str(value_to_write))
   fid.write(",")
   fid.write(str(current_height))
   fid.write(',')
   fid.write(str(current_weight))
   fid.write(',')
   fid.write(str(current_wingspan))
   fid.write(',')
   fid.write(str(current_speed)) 
   fid.write("\n")
  



