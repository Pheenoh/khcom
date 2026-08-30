.syntax unified
	.align 2, 0
	.global func_080D358C
	.thumb
	.thumb_func
	.type func_080D358C, %function
func_080D358C: @ 080D358C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl func_080DEE44
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _080D35AA
	movs r0, #0x00
	b _080D35AC
_080D35AA:
	movs r0, #0x01
_080D35AC:
	pop {r1}
	bx r1
.syntax divided
