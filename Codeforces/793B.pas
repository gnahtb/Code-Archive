uses math;
const fi='';
      fo='';
      lim=1000;
var a:array[0..lim+5,0..lim+5] of char;
    h,v:array[0..lim+5,0..lim+5] of longint;
    i1,j1,i2,j2,m,n:longint;
    r:string;
procedure enter;
var i,j:longint;
begin
        assign(input,fi);
        reset(input);
        readln(n,m);
        for i:=1 to n do
                begin
                        for j:=1 to m do
                                begin
                                        read(a[i,j]);
                                        if a[i,j]='S' then
                                                begin
                                                        i1:=i;
                                                        j1:=j;
                                                end;
                                        if a[i,j]='T' then
                                                begin
                                                        i2:=i;
                                                        j2:=j;
                                                end;
                                end;
                        readln;
                end;
        close(input);
end;
procedure init;
var i,j:longint;
begin
        fillchar(h,sizeof(h),0);
        fillchar(v,sizeof(v),0);
        for i:=1 to n do
                for j:=1 to m do
                        begin
                                h[i,j]:=h[i,j-1];
                                v[i,j]:=v[i-1,j];
                                if a[i,j]='*' then
                                        begin
                                                inc(h[i,j]);
                                                inc(v[i,j]);
                                        end;
                        end;
end;
procedure solve;
var i,j,t1,t2,t3:longint;
begin
        for i:=1 to n do
                begin
                        t1:=v[max(i,i1),j1]-v[min(i,i1)-1,j1];
                        t2:=v[max(i,i2),j2]-v[min(i,i2)-1,j2];
                        t3:=h[i,max(j1,j2)]-h[i,min(j1,j2)-1];
                        if t1+t2+t3=0 then
                                begin
                                        r:='YES';
                                        exit;
                                end;
                end;
        for j:=1 to m do
                begin
                        t1:=h[i1,max(j,j1)]-h[i1,min(j,j1)-1];
                        t2:=h[i2,max(j,j2)]-h[i2,min(j,j2)-1];
                        t3:=v[max(i1,i2),j]-v[min(i1,i2)-1,j];
                        if t1+t2+t3=0 then
                                begin
                                        r:='YES';
                                        exit;
                                end;
                end;
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
        init;
        r:='NO';
        solve;
        print;
end.
