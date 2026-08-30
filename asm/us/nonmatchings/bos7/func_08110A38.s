.syntax unified
	.align 2, 0
	.global func_08110A38
	.thumb
	.thumb_func
	.type func_08110A38, %function
func_08110A38: @ 08110A38
	push {r4, lr}
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _08110A56
	cmp r1, #0x00
	beq _08110A56
	lsls r0, r1, #0x08
	adds r1, r2, #0x0
	bl func_0811D5EC
	adds r3, r0, #0x0
	ldr r4, _08110A5C @ =0x09A4FD5C
	ldr r0, [r4, #0x00]
	cmp r3, r0
	bgt _08110A60
_08110A56:
	movs r0, #0x00
	b _08110A90
	.byte 0x00, 0x00
_08110A5C: .4byte 0x09A4FD5C
_08110A60:
	movs r1, #0x08
	movs r2, #0x10
	ldr r0, [r4, #0x40]
	cmp r3, r0
	beq _08110A8E
_08110A6A:
	lsls r0, r2, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	cmp r3, r0
	bge _08110A78
	subs r2, r2, r1
	b _08110A7A
_08110A78:
	adds r2, r2, r1
_08110A7A:
	lsrs r0, r1, #0x1F
	adds r0, r1, r0
	asrs r1, r0, #0x01
	cmp r1, #0x00
	beq _08110A8E
	lsls r0, r2, #0x02
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	cmp r3, r0
	bne _08110A6A
_08110A8E:
	adds r0, r2, #0x0
_08110A90:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
