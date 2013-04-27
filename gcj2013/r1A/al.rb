(1..gets.to_i).each { |t|
  r,tl = gets.split(' ').map{|s| s.to_i}
  rslt = 0

  a = 0
  b = 1100000000
  
  while a < b-1 do
    m = a + (b-a) / 2

    n = 2*m*m + (2*r-1)*m
    if tl >= n then
      a = m
    else
      b = m
    end
  end
  
  print "Case \##{t}: #{a}\n"    
}
