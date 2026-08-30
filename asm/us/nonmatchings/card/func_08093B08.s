.syntax unified
	.align 2, 0
	.global func_08093B08
	.thumb
	.thumb_func
	.type func_08093B08, %function
func_08093B08: @ 08093B08
	push {r4, lr}
	lsls r0, r0, #0x10
	movs r2, #0x00
	lsrs r1, r0, #0x10
	adds r0, r1, #0x0
	adds r0, #0x0A
	cmp r1, r0
	bge _08093B2C
	ldr r4, _08093B34 @ =0x0203A8C0
	adds r3, r0, #0x0
_08093B1C:
	adds r0, r1, r4
	ldrb r0, [r0, #0x00]
	adds r0, r2, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	adds r1, #0x01
	cmp r1, r3
	blt _08093B1C
_08093B2C:
	adds r0, r2, #0x0
	pop {r4}
	pop {r1}
	bx r1
_08093B34: .4byte 0x0203A8C0
.syntax divided
