.syntax unified
	.align 2, 0
	.global func_080C9FBC
	.thumb
	.thumb_func
	.type func_080C9FBC, %function
func_080C9FBC: @ 080C9FBC
	push {r4, r5, r6, lr}
	ldr r0, _080CA004 @ =0x02034DE0
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080CA08C
	ldr r0, _080CA008 @ =0x02034DE1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C9FDE
	ldr r0, _080CA00C @ =0x0203C3EC
	ldr r2, [r0, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x04]
	ldr r2, [r2, #0x08]
	adds r1, r1, r2
	bl func_080C9FA8
_080C9FDE:
	ldr r3, _080CA00C @ =0x0203C3EC
	ldr r1, [r3, #0x00]
	ldr r2, [r1, #0x04]
	ldr r0, [r1, #0x08]
	adds r5, r2, r0
	ldr r0, _080CA010 @ =0x0203C404
	ldr r4, [r0, #0x00]
	ldr r1, [r1, #0x00]
	subs r2, r4, r1
	adds r6, r3, #0x0
	adds r3, r0, #0x0
	cmp r2, #0x00
	blt _080CA01C
	ldr r0, _080CA014 @ =0x0000EFFF
	cmp r2, r0
	ble _080CA026
	ldr r4, _080CA018 @ =0x0203C400
	b _080CA080
	.byte 0x00, 0x00
_080CA004: .4byte 0x02034DE0
_080CA008: .4byte 0x02034DE1
_080CA00C: .4byte 0x0203C3EC
_080CA010: .4byte 0x0203C404
_080CA014: .4byte 0x0000EFFF
_080CA018: .4byte 0x0203C400
_080CA01C:
	subs r1, r1, r4
	ldr r0, _080CA03C @ =0x0000EFFF
	ldr r4, _080CA040 @ =0x0203C400
	cmp r1, r0
	bgt _080CA080
_080CA026:
	ldr r0, _080CA040 @ =0x0203C400
	ldr r1, [r0, #0x00]
	subs r2, r1, r5
	adds r4, r0, #0x0
	cmp r2, #0x00
	blt _080CA048
	ldr r0, _080CA044 @ =0x00009FFF
	cmp r2, r0
	ble _080CA050
	b _080CA080
	.byte 0x00, 0x00
_080CA03C: .4byte 0x0000EFFF
_080CA040: .4byte 0x0203C400
_080CA044: .4byte 0x00009FFF
_080CA048:
	subs r1, r5, r1
	ldr r0, _080CA074 @ =0x00009FFF
	cmp r1, r0
	bgt _080CA080
_080CA050:
	ldr r2, _080CA078 @ =0x0203C3FC
	ldr r1, [r6, #0x00]
	ldr r0, [r3, #0x00]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	str r0, [r2, #0x00]
	ldr r2, _080CA07C @ =0x0203C408
	ldr r0, [r4, #0x00]
	adds r0, r0, r5
	lsrs r1, r0, #0x1F
	adds r0, r0, r1
	asrs r0, r0, #0x01
	str r0, [r2, #0x00]
	b _080CA08C
	.byte 0x00, 0x00
_080CA074: .4byte 0x00009FFF
_080CA078: .4byte 0x0203C3FC
_080CA07C: .4byte 0x0203C408
_080CA080:
	ldr r1, _080CA094 @ =0x0203C3FC
	ldr r0, [r3, #0x00]
	str r0, [r1, #0x00]
	ldr r1, _080CA098 @ =0x0203C408
	ldr r0, [r4, #0x00]
	str r0, [r1, #0x00]
_080CA08C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CA094: .4byte 0x0203C3FC
_080CA098: .4byte 0x0203C408
.syntax divided
