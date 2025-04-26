# PhoneBook

## Requirement

- Implement two classes:
  - Anything that will always be used inside a class is private.
  - Anything that can be use outside a class is public.
  - **PhoneBook**
    - It has an array of contacts.
    - It can store a maximum of 8 contacts. if the use tries to add a 9th contact, replace the oldest one by the new one.
    - Dynamic alloction is forbidden.
  - **Contact** - Phone book contact.
- At program start-up, the phonebook is empty and the user is prompted to enter one of three commands.
  - **ADD**
    - They are prompted to input the information of the new contact one field at a time.
    - Contact fields are:
      - First name
      - Phone number
      - Darkest secret
      - A saved contact can't have empty fields
  - **SEARCH**
    - Display the saved contacts as a list of 4 columns

	| Index |Firstname |Lastname |Nickname	|
	|-------:|--------:|--------:|---------:|
	|0		|aaa	 |aaa		|a			|
	|1		|bbb	 |bbb		|b		  	|
	|2		|ccc	 |ccc 		|c			|

	- Each column must be 10 characters wide. A pipe character ('|') separates them.
	- The text must be right aligned. 
	- If the text is longer the column, it must be truncated and the last displayable character must replaced by as dot.
	- Then, prompt the use again for the index of the entry display. If the index is out of range or wrong, **define the relecant behaviour**.
	- Display the contact information, one field per line.

  - **EXIT**
    - The program quits and the contacts are lost forever.
  - **Any other input is ignored.**