import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LargeIntestinesComponent } from './large-intestines.component';

describe('LargeIntestinesComponent', () => {
  let component: LargeIntestinesComponent;
  let fixture: ComponentFixture<LargeIntestinesComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LargeIntestinesComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LargeIntestinesComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
