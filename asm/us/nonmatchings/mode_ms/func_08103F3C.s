.syntax unified
	.align 2, 0
	.global func_08103F3C
	.thumb
	.thumb_func
	.type func_08103F3C, %function
func_08103F3C: @ 08103F3C
	push {r4, lr}
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0x00
	ldr r0, _08103F90 @ =0x09993334
	ldrh r1, [r0, #0x00]
	cmp r2, r1
	bcc _08103F7C
	adds r4, r0, #0x0
_08103F5C:
	lsls r0, r3, #0x10
	movs r3, #0x80
	lsls r3, r3, #0x09
	adds r0, r0, r3
	lsrs r3, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x09
	bgt _08103F7C
	lsls r0, r0, #0x01
	adds r0, r0, r4
	ldrh r0, [r0, #0x00]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r2, r1
	bcs _08103F5C
_08103F7C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x0A
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
_08103F90: .4byte 0x09993334
.syntax divided
