import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { SmallIntestinesComponent } from './small-intestines.component';

describe('SmallIntestinesComponent', () => {
  let component: SmallIntestinesComponent;
  let fixture: ComponentFixture<SmallIntestinesComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ SmallIntestinesComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(SmallIntestinesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
