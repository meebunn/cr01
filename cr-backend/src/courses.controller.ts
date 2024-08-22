import { Controller, Get } from '@nestjs/common';
import { Course } from './interfaces/courses.interface' ; 
import { CoursesService } from './courses.service';

@Controller('courses')
export class CoursesController {
  constructor(private coursesService : CoursesService) {} // inject by provider 

  @Get()
  async findAll() : Promise<Course[]> {
    return this.coursesService.findAll() ;
  }
}


