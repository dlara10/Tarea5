import numpy as np
import matplotlib.pyplot as pl

radio, velocitie = np.genfromtxt("RadialVelocities.dat").T 
mb, md, mh = np.genfromtxt("parametros.dat").T

pl.figure()
pl.plot(radio, velocitie, '-g', label='Radial Velocities')
pl.legend(loc=0)
pl.title('Radial Velocities')
pl.xlabel('Radios')
pl.ylabel('Velocities')
pl.savefig('RadialVelocities.png')
  
  