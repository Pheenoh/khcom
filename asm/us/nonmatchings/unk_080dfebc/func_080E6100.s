.syntax unified
	.align 2, 0
	.global func_080E6100
	.thumb
	.thumb_func
	.type func_080E6100, %function
func_080E6100: @ 080E6100
	push {r4, lr}
	add sp, #-0x020
	ldr r0, _080E6114 @ =0x0203C7AC
	ldr r0, [r0, #0x00]
	ldrb r0, [r0, #0x0D]
	cmp r0, #0x03
	beq _080E6118
	cmp r0, #0x05
	beq _080E612E
	b _080E6170
_080E6114: .4byte 0x0203C7AC
_080E6118:
	mov r0, sp
	movs r1, #0x03
	movs r2, #0x03
	bl func_080E5C00
	mov r0, sp
	movs r1, #0x02
	movs r2, #0x02
	bl func_080E5C00
	b _080E6170
_080E612E:
	movs r4, #0x02
_080E6130:
	ldr r0, _080E6140 @ =0x0203C590
	ldrb r0, [r0, #0x04]
	cmp r0, #0x02
	bne _080E6144
	mov r0, sp
	movs r1, #0x04
	b _080E6158
	.byte 0x00, 0x00
_080E6140: .4byte 0x0203C590
_080E6144:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080E6160
	mov r0, sp
	movs r1, #0x00
_080E6158:
	movs r2, #0x00
	bl func_080E5C00
	b _080E616A
_080E6160:
	mov r0, sp
	movs r1, #0x01
	movs r2, #0x00
	bl func_080E5C00
_080E616A:
	subs r4, #0x01
	cmp r4, #0x00
	bge _080E6130
_080E6170:
	add sp, #0x020
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
