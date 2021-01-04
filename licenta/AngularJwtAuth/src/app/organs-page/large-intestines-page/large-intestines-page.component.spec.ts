import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { LargeIntestinesPageComponent } from './large-intestines-page.component';

describe('LargeIntestinesPageComponent', () => {
  let component: LargeIntestinesPageComponent;
  let fixture: ComponentFixture<LargeIntestinesPageComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ LargeIntestinesPageComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(LargeIntestinesPageComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
