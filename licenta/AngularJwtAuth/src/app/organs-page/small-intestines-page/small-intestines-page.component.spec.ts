import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { SmallIntestinesPageComponent } from './small-intestines-page.component';

describe('SmallIntestinesPageComponent', () => {
  let component: SmallIntestinesPageComponent;
  let fixture: ComponentFixture<SmallIntestinesPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ SmallIntestinesPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(SmallIntestinesPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
