#! /bin/sh

# CCM Library compilation script
#     run from distribution directory:  'makelibs.sh'
# When installing on an Intel based platform
#     respond with  y  to the prompt
#     otherwise abort and run the 'non_intel.sh' script first.
# Then run 'makelibs.sh' and respond with n at this prompt. 

LST="cfit complex fft geom intg matrix roots sfunc simu sort statf tseries util xarm"
MDR=`pwd`
LSOD=$MDR/tmp
echo "Intel platform ? (y/n)"
read F
for dr in $LST
  do
    cd $MDR/$dr
    echo `pwd`
    cc -c -O3 *.c
    mv *.o $LSOD
  done

# Compile corrected svd QR support without optimizing
#     The GNU optimizer destroys the fix!
cd $MDR/matrix
cc -c qrb*.c
mv *.o $LSOD
cd $MDR

if [ $F = "y" ]
  then cd $MDR/matrix
    cc -c -O3 solv.s
    mv *.o $LSOD
    cd $MDR/simu
    cc -c -O3 *.s
    mv *.o $LSOD
fi
cd $LSOD
ar r libccm.a *.o
ld -shared -o libccm.so *.o
rm *.o
