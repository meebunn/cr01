import { Injectable } from "@nestjs/common";
import { Course } from "./interfaces/courses.interface";

@Injectable() 
export class CoursesService { 
    async findAll() : Promise<Course[]> { 
        return [
            {id : '100' ,
              number : '01204111',
              title : 'Computer'
            },
            {id : '200' ,
              number : '01204212',
              title : 'discrete'
            },
            {id : '300' ,
              number : '01204313',
              title : 'design'
            },
          ];
    }
}