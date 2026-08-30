.syntax unified
	.align 2, 0
	.global func_080D001C
	.thumb
	.thumb_func
	.type func_080D001C, %function
func_080D001C: @ 080D001C
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r1, [r4, #0x00]
	ldr r0, [r5, #0x00]
	lsls r0, r0, #0x01
	lsls r1, r1, #0x02
	adds r0, r0, r1
	movs r1, #0xF0
	lsls r1, r1, #0x04
	adds r0, r0, r1
	movs r1, #0x05
	bl func_0811D5EC
	str r0, [r4, #0x00]
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	ldr r1, _080D004C @ =0xFFFFF800
	adds r0, r0, r1
	str r0, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080D004C: .4byte 0xFFFFF800
.syntax divided
