const fi='';
      fo='';
      lim=200000;
var a:array[0..lim+5] of longint;
    n,min,c:longint;
procedure enter;
var i:longint;
begin
        readln(n);
        for i:=1 to n do read(a[i]);
end;
{procedure sort(l,r:longint);
var i,j,x,y:longint;
begin
        i:=l;
        j:=r;
        x:=a[(l+r) div 2];
        repeat
                while a[i]<x do inc(i);
                while x<a[j] do dec(j);
                if not(i>j) then
                        begin
                                y:=a[i];
                                a[i]:=a[j];
                                a[j]:=y;
                                inc(i);
                                dec(j);
                        end;
        until i>j;
        if l<j then sort(l,j);
        if i<r then sort(i,r);
end;}
Procedure Sort_Merge (g, d : longint);
Var
   m, i, j, k : longint;
   s : array[0..lim+5] of longint;
Begin
     If d > g Then
     Begin
          m := (g + d) Div 2;
          Sort_Merge (g, m);
          Sort_Merge (m + 1, d);

     For i := m DownTo g Do
              s[i] := a[i];

     For j := m + 1 To d Do
              s[d + m + 1 - j] := a[j];

     i := g; j := d;
          For k := g To d Do
          Begin
               If s[i] < s[j] Then
               Begin
                    a[k] := s[i];
                    i := i + 1;
               End
               Else
                   Begin
                         a[k] := s[j];
                         j := j - 1;
                   End;
          End;
     End;
End;

procedure solve;
var i:longint;
begin
        c:=0;
        min:=maxlongint;
        for i:=1 to n-1 do
                if a[i+1]-a[i]<min then
                        begin
                                min:=a[i+1]-a[i];
                                c:=1;
                        end
                else if a[i+1]-a[i]=min then inc(c);
end;
procedure print;
begin
        writeln(min,#32,c);
end;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        enter;
        sort_merge(1,n);
        solve;
        print;
        close(input);
        close(output);
end.

