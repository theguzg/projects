import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { AnaphylaxisComponent } from './anaphylaxis.component';

describe('AnaphylaxisComponent', () => {
  let component: AnaphylaxisComponent;
  let fixture: ComponentFixture<AnaphylaxisComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AnaphylaxisComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(AnaphylaxisComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
