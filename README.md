# Roob's Kitchen App *[Soon translated to Rust]*
This app was built with C++20, I built it because i was bored and can't progress further with my custom math query language [**mmqlc**](https://www.github.com/MTalha-Codes/mmqlc).
</br>**Roob's Kitchen App** has the following features:
## Notable Features 
- User Authentication System
- Cart Tracking System

### User Authentication System
- Email Validation (  ***Email must contain '@'***  )
- Password Validation ( **Length of Password $\geq$ 8 characters** )
- Username Validation ( **Verify the Uniqueness of Chosen Username** )
- Credentials Storing ( **Stores the Credentials into file for later Logins** )

### Cart Tracking System
- If **Order** hasn't been placed then It stores the current cart into a temporary file called *CART* which is automatically deleted when the user logs in next time.

## Limitations
- It uses a hardcoded food-list.
