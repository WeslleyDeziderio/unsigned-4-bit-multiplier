library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity mult4 is
port (
    a :in std_logic_vector(3 downto 0);
    b :in std_logic_vector(3 downto 0);
    product :out std_logic_vector(7 downto 0);
    cout : out std_logic;
    vdd :in std_logic;
    vss :in std_logic
);
end mult4;

architecture mult4_behavioral of mult4 is
begin
    process(a, b)
    variable a_value, b_value, cout_tmp: std_logic_vector(7 downto 0);
    begin
        a_value := "00000000";
        b_value := "0000" & b;
        cout_tmp := "0";

        for i in 0 to 3 loop
            if a_value(i) = '1' then
                a_value := a_value + b_value;
                if a_value(7) = '1' then
                    cout_tmp := '1';
                else
                    cout_tmp := '0';
                end if;
            end if;
            b_value := b_value(6 downto 0) & '0';
        end loop;
        product <= a_value;
        cout <= cout_tmp;
    end process;
end mult4_behavioral;
