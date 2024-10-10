for x in *; do 
  if ! [ -x $x ]; then continue; fi; 
  echo '<<' $x '>>';  
  ./$x; 
done;
