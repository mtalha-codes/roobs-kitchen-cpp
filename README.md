# Roob's Kitchen App [Archived]

> [!NOTE]
> This codebase is archived as of now **2025-08-15**, because a [**rust rewrite**](https://www.github,com/mtalha-codes/roobs-kitchen-rs) is in progress.

This app was primarily built with C++20 to showcase app design to senior (btw, elder sister of my friend tbh) from UETM who is a data science graduate to showcase her app design. Basically she didn't knew how an app look like in the codebase because she was fully pursuing data science and unfortunately the final year project that was associated to her was to make an Cross Platform Mobile App Called **Roob's Kitchen App**.


In the meantime, I also got bored with my own project called [**mmqlc**](https://www.github.com/mtalha-codes/mmqlc) which is essentially a math language built with C++23.

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
