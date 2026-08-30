.syntax unified
	.align 2, 0
	.global func_080E7DB8
	.thumb
	.thumb_func
	.type func_080E7DB8, %function
func_080E7DB8: @ 080E7DB8
	push {r4, lr}
	adds r4, r1, #0x0
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080E7DC8
	b _080E7DE8
_080E7DC4:
	movs r0, #0x00
	b _080E7DEA
_080E7DC8:
	movs r3, #0x00
	ldr r0, _080E7DF0 @ =0x02034F78
	ldrb r2, [r0, #0x00]
	cmp r3, r2
	bge _080E7DE8
	ldr r0, _080E7DF4 @ =0x0203C7B8
	adds r1, r2, #0x0
	ldr r2, [r0, #0x00]
_080E7DD8:
	ldr r0, [r2, #0x14]
	ldr r0, [r0, #0x04]
	cmp r0, r4
	beq _080E7DC4
	adds r2, #0x18
	adds r3, #0x01
	cmp r3, r1
	blt _080E7DD8
_080E7DE8:
	movs r0, #0x01
_080E7DEA:
	pop {r4}
	pop {r1}
	bx r1
_080E7DF0: .4byte 0x02034F78
_080E7DF4: .4byte 0x0203C7B8
.syntax divided
