
#ifndef COMPILER_ERRORHANDLER_H_INCLUDED
#define COMPILER_ERRORHANDLER_H_INCLUDED

#include <string>

namespace Compiler
{
    struct TokenLoc;

    /// \brief Error handling
    ///
    /// This class collects errors and provides an interface for reporting them to the user.

    class ErrorHandler
    {
            int mWarnings;
            int mErrors;

        protected:

            enum Type
            {
                WarningMessage, ErrorMessage
            };

        private:

        // mutators

            virtual void report (const std::string& message, const TokenLoc& loc, Type type) = 0;
            ///< Report error to the user.

            virtual void report (const std::string& message, Type type) = 0;
            ///< Report a file related error

        public:

            ErrorHandler();
		    ///< constructor

            virtual ~ErrorHandler();
		    ///< destructor

            bool isGood() const;
            ///< Was compiling successful?

            int countErrors() const;
            ///< Return number of errors

            int countWarnings() const;
            ///< Return number of warnings

            void warning (const std::string& message, const TokenLoc& loc);
            ///< Generate a warning message.

            void error (const std::string& message, const TokenLoc& loc);
            ///< Generate an error message.

            void endOfFile();
            ///< Generate an error message for an unexpected EOF.

           virtual void reset();
            ///< Remove all previous error/warning events
    };
}

#endif
