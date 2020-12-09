var m,n,a,t1,t2,r:int64;
begin
        readln(m,n,a);
        t1:=m div a;
        if m mod a>0 then inc(t1);
        t2:=n div a;
        if n mod a>0 then inc(t2);
        r:=t1*t2;
        write(r);
end.
