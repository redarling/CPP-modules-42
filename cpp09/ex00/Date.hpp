#pragma once

typedef struct s_date
{
    int year;
    int month;
    int day;

    bool operator<(const s_date& other) const
    {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    bool operator==(const s_date& other) const
    {
        return (year == other.year && month == other.month && day == other.day);
    }

    bool operator!=(const s_date& other) const
    {
        return !(*this == other);
    }

} t_date;