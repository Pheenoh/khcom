.syntax unified
	.align 2, 0
	.global func_080083F8
	.thumb
	.thumb_func
	.type func_080083F8, %function
func_080083F8: @ 080083F8
	adds r2, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r3, r1, #0x0
	cmp r1, #0x10
	beq _08008448
	cmp r1, #0x10
	bgt _08008420
	cmp r1, #0x02
	beq _08008460
	cmp r1, #0x02
	bgt _08008416
	cmp r1, #0x01
	beq _0800845C
	b _0800846A
_08008416:
	cmp r1, #0x04
	beq _08008468
	cmp r1, #0x08
	beq _08008464
	b _0800846A
_08008420:
	cmp r1, #0x80
	beq _08008450
	cmp r1, #0x80
	bgt _08008432
	cmp r1, #0x20
	beq _08008444
	cmp r1, #0x40
	beq _0800844C
	b _0800846A
_08008432:
	movs r1, #0x80
	lsls r1, r1, #0x01
	cmp r3, r1
	beq _08008458
	movs r1, #0x80
	lsls r1, r1, #0x02
	cmp r3, r1
	beq _08008454
	b _0800846A
_08008444:
	ldrb r0, [r2, #0x12]
	b _0800846A
_08008448:
	ldrb r0, [r2, #0x13]
	b _0800846A
_0800844C:
	ldrb r0, [r2, #0x14]
	b _0800846A
_08008450:
	ldrb r0, [r2, #0x15]
	b _0800846A
_08008454:
	ldrb r0, [r2, #0x18]
	b _0800846A
_08008458:
	ldrb r0, [r2, #0x19]
	b _0800846A
_0800845C:
	ldrb r0, [r2, #0x16]
	b _0800846A
_08008460:
	ldrb r0, [r2, #0x17]
	b _0800846A
_08008464:
	ldrb r0, [r2, #0x1A]
	b _0800846A
_08008468:
	ldrb r0, [r2, #0x1B]
_0800846A:
	bx lr
.syntax divided
