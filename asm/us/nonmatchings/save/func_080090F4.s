.syntax unified
	.align 2, 0
	.global func_080090F4
	.thumb
	.thumb_func
	.type func_080090F4, %function
func_080090F4: @ 080090F4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r6, _08009144 @ =0x00000F14
	adds r0, r6, #0x0
	bl func_08000918
	mov r8, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r0, _08009148 @ =0x00001E28
	muls r0, r4
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	adds r1, r5, #0x0
	muls r1, r6
	ldr r2, _0800914C @ =0x0E002F20
	adds r1, r1, r2
	adds r0, r0, r1
	mov r1, r8
	mov r2, r8
	adds r3, r6, #0x0
	bl func_08008AD8
	adds r4, r0, #0x0
	mov r0, r8
	bl func_080009C4
	adds r0, r4, #0x0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_08009144: .4byte 0x00000F14
_08009148: .4byte 0x00001E28
_0800914C: .4byte 0x0E002F20
.syntax divided
