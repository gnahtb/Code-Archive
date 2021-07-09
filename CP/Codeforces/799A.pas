const fi='';
      fo='';
var n,t,a,x,t1,t2,k,d:longint;
    r:string;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(n,t,k,d);
        r:='YES';
        a:=t;
        while a<d do a:=a+t;
        n:=n-(a div t)*k;
        if (d<a) and (n<=0) then r:='NO';
        if (d=a) and (n<=k) then r:='NO';
        write(r);
        close(input);
        close(output);
end.
