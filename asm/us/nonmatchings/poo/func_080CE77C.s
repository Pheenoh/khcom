.syntax unified
	.align 2, 0
	.global func_080CE77C
	.thumb
	.thumb_func
	.type func_080CE77C, %function
func_080CE77C: @ 080CE77C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	adds r0, #0x0C
	bl func_08005B64
	adds r0, r6, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CE7DA
	cmp r0, #0x01
	bne _080CE79E
	movs r5, #0x01
	b _080CE7DC
_080CE79E:
	cmp r0, #0x02
	bne _080CE7DA
	adds r0, r6, #0x0
	adds r0, #0xB8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x53
	beq _080CE7BE
	cmp r0, #0x53
	ble _080CE7CE
	cmp r0, #0xAD
	beq _080CE7BA
	cmp r0, #0xD3
	beq _080CE7C2
	b _080CE7CE
_080CE7BA:
	movs r5, #0x02
	b _080CE7C4
_080CE7BE:
	movs r5, #0x02
	b _080CE7D0
_080CE7C2:
	movs r5, #0x03
_080CE7C4:
	adds r1, r6, #0x0
	adds r1, #0x24
	movs r0, #0x00
	strb r0, [r1, #0x00]
	b _080CE7DC
_080CE7CE:
	movs r5, #0x03
_080CE7D0:
	adds r1, r6, #0x0
	adds r1, #0x24
	movs r0, #0x01
	strb r0, [r1, #0x00]
	b _080CE7DC
_080CE7DA:
	movs r5, #0x00
_080CE7DC:
	ldrh r0, [r6, #0x26]
	cmp r0, r5
	beq _080CE80C
	strh r5, [r6, #0x26]
	adds r0, r6, #0x0
	adds r0, #0x0C
	ldr r4, _080CE814 @ =0x096FD59C
	lsls r5, r5, #0x04
	adds r2, r5, r4
	ldrh r1, [r2, #0x0C]
	ldr r3, [r2, #0x00]
	adds r2, r4, #0x4
	adds r2, r5, r2
	ldr r2, [r2, #0x00]
	str r2, [sp, #0x000]
	adds r2, r7, #0x0
	bl func_08005974
	ldr r0, [r6, #0x00]
	adds r4, #0x08
	adds r5, r5, r4
	ldr r1, [r5, #0x00]
	bl func_08002A10
_080CE80C:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CE814: .4byte 0x096FD59C
.syntax divided
