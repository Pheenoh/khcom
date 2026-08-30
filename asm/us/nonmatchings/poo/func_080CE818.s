.syntax unified
	.align 2, 0
	.global func_080CE818
	.thumb
	.thumb_func
	.type func_080CE818, %function
func_080CE818: @ 080CE818
	push {r4, r5, lr}
	add sp, #-0x020
	adds r3, r0, #0x0
	mov r1, sp
	ldr r0, _080CE874 @ =0x096FD61C
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4}
	stm r1!, {r2, r4}
	ldr r1, _080CE878 @ =0x096FD59C
	ldrh r0, [r3, #0x26]
	lsls r0, r0, #0x04
	adds r0, r0, r1
	ldrh r1, [r0, #0x0C]
	ldr r0, [r0, #0x00]
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r1, [r1, #0x00]
	adds r2, r3, #0x0
	adds r2, #0xBE
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldrh r1, [r0, #0x08]
	adds r0, r3, #0x0
	adds r0, #0xBC
	strh r1, [r0, #0x00]
	adds r1, r3, #0x0
	adds r1, #0xB0
	ldrh r0, [r2, #0x00]
	lsls r0, r0, #0x02
	add r0, sp
	ldr r0, [r0, #0x00]
	ldr r5, _080CE87C @ =0xFFFFE800
	adds r0, r0, r5
	str r0, [r1, #0x00]
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	strh r0, [r2, #0x00]
	add sp, #0x020
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CE874: .4byte 0x096FD61C
_080CE878: .4byte 0x096FD59C
_080CE87C: .4byte 0xFFFFE800
.syntax divided
