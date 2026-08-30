.syntax unified
	.align 2, 0
	.global func_08110A98
	.thumb
	.thumb_func
	.type func_08110A98, %function
func_08110A98: @ 08110A98
	push {r4, r5, lr}
	subs r5, r0, r2
	subs r4, r1, r3
	adds r1, r5, #0x0
	cmp r5, #0x00
	bge _08110AA6
	negs r1, r5
_08110AA6:
	adds r0, r4, #0x0
	cmp r4, #0x00
	bge _08110AAE
	negs r0, r4
_08110AAE:
	cmp r1, r0
	blt _08110ACA
	adds r0, r5, #0x0
	cmp r5, #0x00
	bge _08110ABA
	negs r0, r5
_08110ABA:
	adds r1, r4, #0x0
	cmp r4, #0x00
	bge _08110AC2
	negs r1, r4
_08110AC2:
	bl func_08110A38
	adds r1, r0, #0x0
	b _08110AE2
_08110ACA:
	adds r0, r4, #0x0
	cmp r4, #0x00
	bge _08110AD2
	negs r0, r4
_08110AD2:
	adds r1, r5, #0x0
	cmp r5, #0x00
	bge _08110ADA
	negs r1, r5
_08110ADA:
	bl func_08110A38
	movs r1, #0x3F
	subs r1, r1, r0
_08110AE2:
	cmp r5, #0x00
	blt _08110AF2
	cmp r4, #0x00
	blt _08110B00
	movs r0, #0x3F
	subs r1, r0, r1
	adds r1, #0xC0
	b _08110B00
_08110AF2:
	cmp r4, #0x00
	blt _08110AFA
	adds r1, #0x80
	b _08110B00
_08110AFA:
	movs r0, #0x3F
	subs r1, r0, r1
	adds r1, #0x40
_08110B00:
	movs r0, #0xFF
	subs r1, r0, r1
	adds r1, #0x41
	ands r1, r0
	adds r0, r1, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
