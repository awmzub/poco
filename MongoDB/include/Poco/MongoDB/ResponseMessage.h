//
// ResponseMessage.h
//
// $Id$
//
// Library: MongoDB
// Package: MongoDB
// Module:  ResponseMessage
//
// Definition of the ResponseMessage class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef MongoDB_ResponseMessage_INCLUDED
#define MongoDB_ResponseMessage_INCLUDED


#include "Poco/MongoDB/MongoDB.h"
#include "Poco/MongoDB/Message.h"
#include "Poco/MongoDB/Document.h"
#include <istream>


namespace Poco {
namespace MongoDB {


class MongoDB_API ResponseMessage : public Message
	/// Class that represents a response (OP_REPLY) from MongoDB
{
public:
	ResponseMessage();
		/// Constructor

	virtual ~ResponseMessage();
		/// Destructor

	Int64 cursorID() const;
		/// Returns the cursor id

	void clear();
		/// Clears the response

	size_t count() const;
		/// Returns the number of documents in the response

	Document::Vector& documents();
		/// Returns the retrieved documents

	bool empty() const;
		/// Returns true when the response doesn't contain any documents

	bool hasDocuments() const;
		/// Returns true when there is at least one document

	void read(std::istream& istr);
		/// Reads the response from the stream

private:
	Int32 _responseFlags;
	Int64 _cursorID;
	Int32 _startingFrom;
	Int32 _numberReturned;
	Document::Vector _documents;
};


inline size_t ResponseMessage::count() const
{
	return _documents.size();
}


inline bool ResponseMessage::empty() const
{
	return _documents.size() == 0;
}


inline Int64 ResponseMessage::cursorID() const
{
	return _cursorID;
}


inline Document::Vector& ResponseMessage::documents()
{
	return _documents;
}


inline bool ResponseMessage::hasDocuments() const
{
	return _documents.size() > 0;
}


} } // namespace Poco::MongoDB


#endif //MongoDB_ResponseMessage_INCLUDED