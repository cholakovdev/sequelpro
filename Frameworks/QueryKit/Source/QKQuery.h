//
//  $Id: QKQuery.h 3421 2011-09-10 22:58:45Z stuart02 $
//
//  QKQuery.h
//  QueryKit
//
//  Created by Stuart Connolly (stuconnolly.com) on September 4, 2011
//  Copyright (c) 2011 Stuart Connolly. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#import "QKQueryTypes.h"
#import "QKQueryDatabases.h"
#import "QKQueryOperators.h"

@class QKQueryOrderBy;
@class QKQueryParameter;
@class QKQueryUpdateParameter;

/**
 * @class QKQuery QKQuery.h
 *
 * @author Stuart Connolly http://stuconnolly.com/
 *
 * Main QueryKit query class.
 */
@interface QKQuery : NSObject 
{
	NSString *_database;
	NSString *_table;
	NSString *_identifierQuote;
	
	NSMutableString *_query;
	
	NSMutableArray *_parameters;
	NSMutableArray *_fields;
	NSMutableArray *_updateParameters;
	NSMutableArray *_groupByFields;
	NSMutableArray *_orderByFields;
	
	QKQueryType _queryType;
	QKQueryDatabase _queryDatabase;
	
	BOOL _useQuotedIdentifiers;
}

/**
 * @property database The database the query is to be run against (optional).
 */
@property(readwrite, retain) NSString *database;

/**
 * @property table The table the query is to be run against.
 */
@property(readwrite, retain) NSString *table; 

/**
 * @property parameters The parameters (constraints) of the query.
 */
@property(readwrite, retain) NSMutableArray *parameters;

/**
 * @property fields The fields of the query.
 */
@property(readwrite, retain) NSMutableArray *fields;

/**
 * @property updateFields The fields of an UPDATE query.
 */
@property(readwrite, retain) NSMutableArray *updateParameters;

/**
 * @property queryType The type of query to be built.
 */
@property(readwrite, assign) QKQueryType queryType;

/**
 * @property queryDatabase The underlying database system this query will be run against.
 */
@property(readwrite, assign) QKQueryDatabase queryDatabase;

/**
 * @property useQuotedIdentifiers Indicates whether or not the query's fields should be quoted.
 */
@property(readwrite, assign) BOOL useQuotedIdentifiers;

/**
 * @property groupByFields The group by fields of the query.
 */
@property(readonly) NSMutableArray *groupByFields;

/**
 * @property orderByFields The order by fields of the query.
 */
@property(readonly) NSMutableArray *orderByFields;

/**
 * @property identifierQuote The character to use when quoting identifiers.
 */
@property(readonly) NSString *identifierQuote;

+ (QKQuery *)queryTable:(NSString *)table;
+ (QKQuery *)queryTable:(NSString *)table database:(NSString *)database;

+ (QKQuery *)selectQueryFromTable:(NSString *)table;
+ (QKQuery *)selectQueryFromTable:(NSString *)table database:(NSString *)database;

- (id)initWithTable:(NSString *)table;
- (id)initWithTable:(NSString *)table database:(NSString *)database;

- (NSString *)query;
- (void)clear;

- (void)addField:(NSString *)field;
- (void)addFields:(NSArray *)fields;

- (void)addParameter:(QKQueryParameter *)parameter;
- (void)addParameter:(NSString *)field operator:(QKQueryOperator)operator value:(id)value;

- (void)addFieldToUpdate:(QKQueryUpdateParameter *)parameter;
- (void)addFieldToUpdate:(NSString *)field toValue:(id)value;

- (void)groupByField:(NSString *)field;
- (void)groupByFields:(NSArray *)fields;

- (void)orderBy:(QKQueryOrderBy *)orderBy;
- (void)orderByField:(NSString *)field descending:(BOOL)descending;

@end
