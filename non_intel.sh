#! /bin/sh

# CCM script to modify source for a non-Intel compilation
#   run from distribution directory:  'non_intel.sh'
# respond to prompt with  y  if processor uses the big-endian byte order
#     typical for UNIX workstations

MDR=`pwd`
cp $MDR/matrix/supp/solv.c $MDR/matrix
rm $MDR/matrix/*.s
echo " .s code replaced in matrix"
cp $MDR/simu/supp/*.c $MDR/simu
rm $MDR/simu/*.s
echo " .s code replaced in simu"
echo  
echo " bigendian byte order (y/n)"
read F
if [ $F = "y" ]
  then cp $MDR/xarm/supp/big-end/*.c $MDR/xarm
  echo " bigend code installed in xarm"
fi
