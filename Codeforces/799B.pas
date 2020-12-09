const fi='';
      fo='';
      lim=200000;
var c,a,b,p,r:array[0..lim+5] of longint;
    f:array[1..3,1..3,0..lim+5] of longint;
    x,s:array[1..3,1..3] of longint;
    m,n:longint;
procedure enter;
var i:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n);
        for i:=1 to n do read(p[i]);
        for i:=1 to n do read(a[i]);
        for i:=1 to n do read(b[i]);
        readln(m);
        for i:=1 to m do read(c[i]);
end;
procedure swap(var x,y:longint);
var t:longint;
begin
        t:=x;
        x:=y;
        y:=t;
end;
procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
        i:=l;
        j:=r;
        x:=p[(l+r) div 2];
        repeat
                while p[i]<x do inc(i);
                while x<p[j] do dec(j);
                if i<=j then
                        begin
                                swap(p[i],p[j]);
                                swap(a[i],a[j]);
                                swap(b[i],b[j]);
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if i<r then sort(i,r);
        if l<j then sort(l,j);
end;
procedure init;
var i:longint;
begin
        fillchar(x,sizeof(x),0);
        fillchar(f,sizeof(f),0);
        for i:=1 to n do
                begin
                        inc(x[a[i],b[i]]);
                        f[a[i],b[i],x[a[i],b[i]]]:=p[i];
                end;
end;
procedure solve;
var i,j,min,xa,xb:longint;
begin
        fillchar(s,sizeof(s),0);
        for i:=1 to m do
                begin
                        min:=maxlongint;
                        xa:=0;
                        xb:=0;
                        for j:=1 to 3 do
                                begin
                                        if (0<f[c[i],j,s[c[i],j]+1]) and (f[c[i],j,s[c[i],j]+1]<min) then
                                                begin
                                                        min:=f[c[i],j,s[c[i],j]+1];
                                                        xa:=c[i];
                                                        xb:=j;
                                                end;
                                        if (0<f[j,c[i],s[j,c[i]]+1]) and (f[j,c[i],s[j,c[i]]+1]<min) then
                                                begin
                                                        min:=f[j,c[i],s[j,c[i]]+1];
                                                        xa:=j;
                                                        xb:=c[i];
                                                end;
                                end;
                        r[i]:=min;
                        if xa=0 then r[i]:=-1;
                        if xa>0 then inc(s[xa,xb]);
                end;
end;
procedure print;
var i:longint;
begin
        assign(output,fo);
        rewrite(output);
        for i:=1 to m do write(r[i],' ');
        close(output);
end;
begin
        enter;
        sort(1,n);
        init;
        solve;
        print;
end.

