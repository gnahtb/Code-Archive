const fi='';
      fo='';
      lim=100000;
var x:array[0..lim+5] of longint;
    r,a,b,c,n:longint;
procedure enter;
var i,t:longint;
begin
        assign(input,fi);
        reset(input);
        readln(a,b,c);
        readln(n);
        for i:=1 to n do read(x[i]);
        close(input);
end;
procedure sort(l,r:longint);
var i,j,x1,y:longint;
begin
        i:=l;
        j:=r;
        x1:=x[(l+r) div 2];
        repeat
                while x[i]<x1 do inc(i);
                while x1<x[j] do dec(j);
                if not(i>j) then
                        begin
                                y:=x[i];
                                x[i]:=x[j];
                                x[j]:=y;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;
procedure solve;
var p1,p2,i:longint;
begin
        p1:=0;
        p2:=0;
        for i:=1 to n do
                if x[i]>b then
                        begin
                                p1:=i;
                                break;
                        end;
        for i:=n downto 1 do
                if x[i]<c then
                        begin
                                p2:=i;
                                break;
                        end;
        r:=p2-p1+1;
        if (r<0) or (p1=0) or (p2=0) or (not a in [x[p1]..x[p2]]) then r:=0;
end;
procedure print;
begin
        assign(output,fo);
        rewrite(output);
        write(r);
        close(output);
end;
begin
        enter;
        sort(1,n);
        solve;
        print;
end.

