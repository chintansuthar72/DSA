Activity-Selection(Activity, start, finish)
     Sort Activity by finish times stored in finish
     Selected = {Activity[1]}
     n = Activity.length
     j = 1
     for i = 2 to n:
         if start[i] ≥ finish[j]:
             Selected = Selected U {Activity[i]}
             j = i
 return Selected